<?php

/**
 * @file
 * Contains RestfulFormatterUnicalJson.
 *
 * Creates a custom formatter for events, so we can further control output on events endpoint.
 */

class RestfulFormatterUnicalJson extends \RestfulFormatterBase implements \RestfulFormatterInterface {

  /**
   * Content Type
   *
   * @var string
   */
  protected $contentType = 'application/json; charset=utf-8';

  /**
   * {@inheritdoc}
   */
  public function prepare(array $data) {
    // If we're returning an error then set the content type to
    // 'application/problem+json; charset=utf-8'.
    if (!empty($data['status']) && floor($data['status'] / 100) != 2) {
      $this->contentType = 'application/problem+json; charset=utf-8';
      return $data;
    }



    // Remove some odd events
    $removeCount = 0;
      foreach($data as $key => &$item) {
        if (!isset($item['date']{0})) {
          $removeCount ++;
          unset($data[$key]);
        }
      }


    $output = array('data' => $data);

    if (!empty($this->handler)) {
      if (
        method_exists($this->handler, 'getTotalCount') &&
        method_exists($this->handler, 'isListRequest') &&
        $this->handler->isListRequest()
      ) {

        // Get the total number of items for the current request without pagination.
        // remove any events from the count if we deleted above.
        // NOTE: The possibility still exists that some events that will eventually
        // be reomoved still show up in the count, as the above loop only works on
        // results returned from that page.

        $output['count'] = $this->handler->getTotalCount() - $removeCount;


      }
      if (method_exists($this->handler, 'additionalHateoas')) {
        $output = array_merge($output, $this->handler->additionalHateoas());
      }

      // Add HATEOAS to the output.
      $this->addHateoas($output);
    }

    return $output;
  }


  /**
   * Add HATEOAS links to list of item.
   *
   * @param $data
   *   The data array after initial massaging.
   */
  protected function addHateoas(array &$data) {
    if (!$this->handler) {
      return;
    }
    $request = $this->handler->getRequest();

    // Get self link.
    $data['self'] = array(
      'title' => 'Self',
      'href' => $this->handler->versionedUrl($this->handler->getPath()),
      'endpoint' => $request['q'],
      'restful_formatter' => 'UniCal Custom Event JSON'
    );

    $page = !empty($request['page']) ? $request['page'] : 1;

    if ($page > 1) {
      $request['page'] = $page - 1;
      $data['previous'] = array(
        'title' => 'Previous',
        'href' => $this->handler->getUrl($request),
      );
    }

    // We know that there are more pages if the total count is bigger than the
    // number of items of the current request plus the number of items in
    // previous pages.
    $items_per_page = $this->handler->getRange();
    $previous_items = ($page - 1) * $items_per_page;
    if (isset($data['count']) && $data['count'] > count($data['data']) + $previous_items) {
      $request['page'] = $page + 1;
      $data['next'] = array(
        'title' => 'Next',
        'href' => $this->handler->getUrl($request),
      );
    }

  }

  /**
   * {@inheritdoc}
   */
  public function render(array $structured_data) {
    return drupal_json_encode($structured_data);
  }

  /**
   * {@inheritdoc}
   */
  public function getContentTypeHeader() {
    return $this->contentType;
  }
}
