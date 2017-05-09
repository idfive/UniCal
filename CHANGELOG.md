1.2 (2017-05-09)
------------  
* Add taxonomies to unical, giving a total of 10 editable taxonomies per install.
* Add endpoints for new taxonomies, calendar_taxonomy_8 through 11.
* Fix calls in taxonomies service to fail gracefully.
* Fix Sites API to check if field exists first.
* Add default terms to calendar_taxonomy_7 in unical_features, to ensure they make
  it into fresh installs.
* Add dependencies to unical_features, to accomplish above.
* Adjust/Fix fields on unical_features to incorporate new taxonomies, as well as
  generalize some default settings.
* Update documentation.

Lots of effort was made to test that there are no breaking changes for backwards
compatability. That being said, if you wish to add the new taxonomies to a previous
install, you will need to either re-enable unical_features, or look to the following:
* Ensure calendar_taxonomy_8 through 11 are added.
* Ensure field taxonomy_8 through 11 are added to the event CT.
* Ensure fields mirroring taxonomy_1 are added for taxonomy_8 through 11 ie:
  (field_taxonomy_8_enabled, field_taxonomy_8_label, field_taxonomy_8) for 8-11.

In testing, re-enabling unical_features added the new fields/taxonomies, while leaving
changed/overridden fields in place. You will, however, need to manually re-arrange
the site and event CT's to clean up. TEST ON STG ENV FIRST!
