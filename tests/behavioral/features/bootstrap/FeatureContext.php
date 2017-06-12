<?php

use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\Behat\Context\SnippetAcceptingContext;



/**
 * Defines application features from the specific context.
 */
class FeatureContext extends RawDrupalContext implements SnippetAcceptingContext
{
    /**
   * Initializes context.
   *
   * Every scenario gets its own context instance.
   * You can also pass arbitrary arguments to the
   * context constructor through behat.yml.
   */
  public function __construct()
  {
    //$base_url = $this->getMinkParameter('base_url');
  }

  /** @BeforeScenario */
  public function beforeScenario()
  {


  }


   /**
    * @Then I wait for the app to load
    */
   public function iWaitForTheAppToLoad()
   {
       $this->getSession()->wait(3000);
   }

    /**
     * @Then I should see some content in the :arg1 element
     */
    public function iShouldSeeSomeContentInTheElement($arg1)
    {
        $session = $this->getSession();
        $element = $session->getPage()->find('css', $arg1);
      //check element content is not empty (returns exception if true)
      if ($element == null) {
          throw new Exception("Text is not found in the '{$arg1}' element.");
      }
    }

    /**
     * @When I click the :arg1 element
     */
    public function iClickTheElement($arg1)
    {
      // Not 100% working in gecko due to geckodriver errors
      $session = $this->getSession();
      $element = $session->getPage()->find('css', $arg1);

      //check element content is not empty (returns exception if true)
      if ($element == null) {
          throw new Exception("The '{$arg1}' element not found.");
      }
      $element->click();
    }

     /**
      * @Given /^I call "([^"]*)"$/
      */
     public function iCall($argument1)
     {
         $base_url = $this->getMinkParameter('base_url');
         $client = new GuzzleHttp\Client();
         $request = $client->request('GET', $base_url . $argument1);
         $this->response = $request->getBody(true);
     }

     /**
      * @Then /^I get a response$/
      */
     public function iGetAResponse()
     {
         if (empty($this->response)) {
             throw new Exception('Did not get a response from the API');
         }
     }

     /**
      * @Given /^the response is JSON$/
      */
     public function theResponseIsJson()
     {
         $data = json_decode($this->response);

         if (empty($data)) {
             throw new Exception("Response was not JSON\n".$this->response);
         }
     }

     /**
      * @Given /^the response contains at least one item$/
      */
     public function theResponseContainsAtLeastOneItem()
     {
         $data = json_decode($this->response);

         if (count($data->data) < 1) {
             throw new Exception('Response did not contain at least one item');
         }
     }

      /**
       * @Given /^the feed contains a calendar endpoint$/
       */
      public function theFeedContainsACalendarEndpoint()
      {
          $data = json_decode($this->response);
          //print_r($data->data[0]->label);
          $programs = $data->data[0];

          if (!isset($programs->label) || $programs->label !== 'Event Search') {
              throw new Exception('The api does not contain the Event Search endpoint.');
          }
      }
}
