/**
 * A demonstration test program for Gimatriya calculation.
 * 
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * Date: 2020-02
 */
//Authors names:Ilana shuchman and Michael Perry
#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>
#include <stdbool.h>

using namespace family;
using namespace std;

TEST_CASE("Wrong adding function"){
    Tree root("michael"); //root
    root.addMother("michael","eli-sheva");

    CHECK(root.relation("eli-sheva")=="mother");
    CHECK_THROWS(root.addMother("moshe","hagit"));
    CHECK_THROWS(root.addFather("moshe","shalom"));
    CHECK_THROWS(root.addMother("michael", "hagit"));
    
}//Wrong adding function


TEST_CASE("Printing Tree"){
    Tree root("michael"); //root

    root.addFather("michael", "yehuda");
    root.addMother("michael", "eli-sheva");   

    root.addFather("yehuda", "shalom");
    root.addMother("yehuda", "soul");
    root.addFather("eli-sheva", "mike");
    root.addMother("eli-sheva", "rina");
    root.addFather("soul", "machluf");
    root.addFather("shalom", "isaac");
    root.addMother("shalom", "ester");
    root.addFather("mike", "avraham");
    root.addMother("mike", "ester");
    root.addFather("rina", "moshe");
    root.addMother("rina", "meriyam");
    
    CHECK_NOTHROW(root.display());

}


TEST_CASE("Checking relation function")
{   
    Tree root("michael"); //root

    root.addFather("michael", "yehuda");
    root.addMother("michael", "eli-sheva");   
    root.addFather("yehuda", "shalom");
    root.addMother("yehuda", "soul");
    root.addFather("eli-sheva", "mike");
    root.addMother("eli-sheva", "rina");
    root.addMother("soul", "tami");
    root.addFather("soul", "machluf");
    root.addFather("shalom", "isaac");
    root.addMother("shalom", "ester");
    root.addFather("mike", "avraham");
    root.addMother("mike", "ester");
    root.addFather("rina", "moshe");
    root.addMother("rina", "meriyam");


    CHECK(root.relation("yehuda") == "father");
    CHECK(root.relation("eli-sheva") == "mother");
    CHECK(root.relation("shalom") == "grandfather");
    CHECK(root.relation("soul") == "grandmother");
    CHECK(root.relation("mike") == "grandfather");
    CHECK(root.relation("rina") == "grandmother");
    CHECK(root.relation("tami") == "great-grandmother");
    CHECK(root.relation("machluf") == "great-grandfather");
    CHECK(root.relation("isaac") == "great-grandfather");
    CHECK(root.relation("ester") == "great-grandmother");
    CHECK(root.relation("avraham") == "great-grandfather");
    CHECK(root.relation("moshe") == "great-grandfather");
    CHECK(root.relation("meriyam") == "great-grandmother");

    CHECK(root.relation("yehuda") != "mother");
    CHECK(root.relation("yehuda") != "grandfather");
    CHECK(root.relation("yehuda") != "grandmother");
    CHECK(root.relation("yehuda") != "great-grandfather");
    CHECK(root.relation("yehuda") != "great-grandmother");

    CHECK(root.relation("eli-sheva") != "father");
    CHECK(root.relation("eli-sheva") != "grandfather");
    CHECK(root.relation("eli-sheva") != "grandmother");
    CHECK(root.relation("eli-sheva") != "great-grandfather");
    CHECK(root.relation("eli-sheva") != "great-grandmother");

    CHECK(root.relation("shalom") != "father");
    CHECK(root.relation("shalom") != "mother");
    CHECK(root.relation("shalom") != "grandmather");
    CHECK(root.relation("shalom") != "great-grandfather");
    CHECK(root.relation("shalom") != "great-grandmother");

    CHECK(root.relation("soul") != "father");
    CHECK(root.relation("soul") != "mother");
    CHECK(root.relation("soul") != "grandfather");
    CHECK(root.relation("soul") != "great-grandfather");
    CHECK(root.relation("soul") != "great-grandmother");

    CHECK(root.relation("mike") != "father");
    CHECK(root.relation("mike") != "mother");
    CHECK(root.relation("mike") != "grandmother");
    CHECK(root.relation("mike") != "great-grandfather");
    CHECK(root.relation("mike") != "great-grandmother");

    CHECK(root.relation("rina") != "father");
    CHECK(root.relation("rina") != "mother");
    CHECK(root.relation("rina") != "grandfather");
    CHECK(root.relation("rina") != "great-grandfather");
    CHECK(root.relation("rina") != "great-grandmother");

    CHECK(root.relation("tami") != "father");
    CHECK(root.relation("tami") != "mother");
    CHECK(root.relation("tami") != "grandfather");
    CHECK(root.relation("tami") != "grandmother");
    CHECK(root.relation("tami") != "great-grandfather");

    CHECK(root.relation("machluf") != "father");
    CHECK(root.relation("machluf") != "mother");
    CHECK(root.relation("machluf") != "grandfather");
    CHECK(root.relation("machluf") != "grandmother");
    CHECK(root.relation("machluf") != "great-grandmother");

    CHECK(root.relation("isaac") != "father");
    CHECK(root.relation("isaac") != "mother");
    CHECK(root.relation("isaac") != "grandfather");
    CHECK(root.relation("isaac") != "grandmother");
    CHECK(root.relation("isaac") != "great-grandmother");

    CHECK(root.relation("ester") != "father");
    CHECK(root.relation("ester") != "mother");
    CHECK(root.relation("ester") != "grandfather");
    CHECK(root.relation("ester") != "grandmother");
    CHECK(root.relation("ester") != "great-grandfather");

    CHECK(root.relation("avraham") != "father");
    CHECK(root.relation("avraham") != "mother");
    CHECK(root.relation("avraham") != "grandfather");
    CHECK(root.relation("avraham") != "grandmother");
    CHECK(root.relation("avraham") != "great-grandmother");

    CHECK(root.relation("moshe") != "father");
    CHECK(root.relation("moshe") != "mother");
    CHECK(root.relation("moshe") != "grandfather");
    CHECK(root.relation("moshe") != "grandmother");
    CHECK(root.relation("moshe") != "great-grandmother");

    CHECK(root.relation("meriyam") != "father");
    CHECK(root.relation("meriyam") != "mother");
    CHECK(root.relation("meriyam") != "grandfather");
    CHECK(root.relation("meriyam") != "grandmother");
    CHECK(root.relation("meriyam") != "great-grandfather");

    CHECK(root.relation("zehavit")=="unrelated");
    CHECK(root.relation("shulamit")=="unrelated");
    CHECK(root.relation("itzik")=="unrelated");
    CHECK(root.relation("zvulun")=="unrelated");

}//relation function

TEST_CASE("Checking find function")
{   
    family::Tree root("michael"); //root
    
    root.addFather("michael", "yehuda");  
    root.addMother("michael","eli-sheva");
    root.addFather("yehuda", "shalom");
    root.addMother("yehuda", "soul");
    root.addMother("soul", "tami");
    root.addFather("soul", "machluf");

    CHECK(root.find("father")=="yehuda");
    CHECK(root.find("mother")=="eli-sheva");
    CHECK(root.find("grandfather")== "shalom");
    CHECK(root.find("grandmother")== "soul");
    CHECK(root.find("great-grandfather")== "machluf");
    CHECK(root.find("great-grandmother")== "tami");

    CHECK_THROWS(root.find("great-great-grandfather"));

}

TEST_CASE("Checking deletion function")
{
    Tree root("michael"); //root
    
    root.addFather("michael", "yehuda");  
    root.addMother("michael","eli-sheva");
    root.addFather("yehuda", "shalom");
    root.addMother("yehuda", "soul");
    root.addMother("soul", "tami");
    root.addFather("soul", "machluf");

    root.remove("machluf");
    CHECK(root.relation("machluf")=="unrelated");
    root.remove("tami");
    CHECK(root.relation("tami")=="unrelated");
    root.remove("soul");
    CHECK(root.relation("soul")=="unrelated");
    root.remove("shalom");
    CHECK(root.relation("shalom")=="unrelated");
    root.remove("eli-sheva");
    CHECK(root.relation("eli-sheva")=="unrelated");
    root.remove("yehuda");
    CHECK(root.relation("yehuda")=="unrelated");


    CHECK_THROWS(root.remove("jesus"));
    CHECK_THROWS(root.remove("michael"));

}//TEST_CASE


