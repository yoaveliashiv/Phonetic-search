
#include "doctest.h"
#include "PhoneticFinder.hpp"
#include <string>
using namespace std;
using namespace phonetic;

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy eli yoav";
            CHECK(find(text, "happi") == string("Happi"));
            CHECK(find(text, "Happi") == string("Happi"));
            CHECK(find(text, "HAPPI") == string("Happi"));
            CHECK(find(text, "HaPpI") == string("Happi"));
            CHECK(find(text, "XXX") == string("xxx"));
            CHECK(find(text, "XxX") == string("xxx"));
            CHECK(find(text, "YYy") == string("yyy"));
            CHECK(find(text, "Yyy") == string("yyy"));
            CHECK(find(text, "ELI") == string("eli"));
            CHECK(find(text, "elI") == string("eli"));
            CHECK(find(text, "Yoav") == string("yoav"));
            CHECK(find(text, "YoaV") == string("yoav"));
            CHECK(find(text, "yoAV") == string("yoav"));
}
TEST_CASE("Test to check space and empty") {
    string text = "Happi xxx yyy eli yoav";
            CHECK_THROWS(find(text, "hap pi") == string("\"err more then one word in s or space\""));
            CHECK_THROWS(find(text, "ha p pi") == string("\"err more then one word in s or space\""));
            CHECK_THROWS(find(text, "  ") == string("\"err more then one word in s or space\""));
            CHECK_THROWS(find(text, " d ") == string("\"err more then one word in s or space\""));
            CHECK_THROWS(find(text, "hpi ") == string("\"err more then one word in s or space\""));
            CHECK_THROWS(find(text, "h t t t p") == string("\"err more then one word in s or space\""));
            CHECK_THROWS(find(text, "h  pi") == string("\"err more then one word in s or space\""));
            CHECK_THROWS(find(text, " p pi") == string("\"err more then one word in s or space\""));
}
TEST_CASE("Test replacement of p and b and f") {
    string text = "xxx happy pub bif";
            CHECK_THROWS(find(text, "ha") == string("\"err more then one word in s or space\""));
            CHECK_THROWS(find(text, "hap") == string("\"err more then one word in s or space\""));
            CHECK(find(text, "habby") == string("happy"));
            CHECK(find(text, "haBby") == string("happy"));
            CHECK(find(text, "hapby") == string("happy"));
            CHECK(find(text, "habpy") == string("happy"));
            CHECK(find(text, "happy") == string("happy"));
            CHECK(find(text, "bub") == string("pub"));
            CHECK(find(text, "pup") == string("pub"));
            CHECK(find(text, "fup") == string("pub"));
            CHECK(find(text, "pif") == string("bif"));
            CHECK(find(text, "fif") == string("bif"));
            CHECK(find(text, "pip") == string("bif"));
}
TEST_CASE("Test replacement of v and w") {
    string text = "vaww win vvww";
            CHECK(find(text, "vvvv") == string("vvww"));
            CHECK(find(text, "wwvv") == string("vvww"));
            CHECK(find(text, "wvwv") == string("vvww"));
            CHECK(find(text, "vwvw") == string("vvww"));
            CHECK(find(text, "vin") == string("win"));
            CHECK(find(text, "wavv") == string("vaww"));
            CHECK(find(text, "waww") == string("vaww"));
            CHECK(find(text, "vavv") == string("vaww"));
            CHECK(find(text, "wawv") == string("vaww"));
}
TEST_CASE("Test replacement of c and k and q") {
    string text = "akcq kkccqq";

            CHECK(find(text, "akcc") == string("akcq"));
            CHECK(find(text, "akqq") == string("akcq"));
            CHECK(find(text, "kkkkqq") == string("kkccqq"));
            CHECK(find(text, "kkcckk") == string("kkccqq"));
            CHECK(find(text, "kkkcqq") == string("kkccqq"));
            CHECK(find(text, "qqccqq") == string("kkccqq"));
            CHECK(find(text, "kkcqqq") == string("kkccqq"));
            CHECK(find(text, "kqcccq") == string("kkccqq"));

}
TEST_CASE("Test replacement of g and j") {
    string text = "jigi jagogg gaggj";
            CHECK(find(text, "gigi") == string("jigi"));
            CHECK(find(text, "jiji") == string("jigi"));
            CHECK(find(text, "giji") == string("jigi"));
            CHECK(find(text, "jajojj") == string("jagogg"));
            CHECK(find(text, "gagogg") == string("jagogg"));
            CHECK(find(text, "jajogg") == string("jagogg"));
            CHECK(find(text, "gagojg") == string("jagogg"));
            CHECK(find(text, "gajjj") == string("gaggj"));
            CHECK(find(text, "jaggj") == string("gaggj"));
            CHECK(find(text, "gajgj") == string("gaggj"));
}
TEST_CASE("Test replacement of s and z") {
    string text = "size sizess ssszz";
            CHECK(find(text, "sise")== string("size"));
            CHECK(find(text, "zize") == string("size"));
            CHECK(find(text, "zise") == string("size"));
            CHECK(find(text, "zisess") == string("sizess"));
            CHECK(find(text, "sizezz") == string("sizess"));
            CHECK(find(text, "sizezs") == string("sizess"));
            CHECK(find(text, "zizezs") == string("sizess"));
            CHECK(find(text, "zzzzz") == string("ssszz"));
            CHECK(find(text, "szszz") == string("ssszz"));
            CHECK(find(text, "zzssz") == string("ssszz"));
            CHECK(find(text, "szssz") == string("ssszz"));
}
TEST_CASE("Test replacement of d and t") {
    string text = "dot teddy tttdd";
            CHECK(find(text, "tot") == string("dot"));
            CHECK(find(text, "dod") == string("dot"));
            CHECK(find(text, "tod") == string("dot"));
            CHECK(find(text, "deddy") == string("teddy"));
            CHECK(find(text, "tetdy") == string("teddy"));
            CHECK(find(text, "tedty") == string("teddy"));
            CHECK(find(text, "tetty") == string("teddy"));
            CHECK(find(text, "ddtdd") == string("tttdd"));
            CHECK(find(text, "ttddd") == string("tttdd"));
            CHECK(find(text, "ttttd") == string("tttdd"));
            CHECK(find(text, "tdtdd") == string("tttdd"));
}
TEST_CASE("Test replacement of o and u") {
    string text = "boub albouou oouuo";
            CHECK(find(text, "buub") == string("boub"));
            CHECK(find(text, "boob") == string("boub"));
            CHECK(find(text, "buob") == string("boub"));
            CHECK(find(text, "alboooo") == string("albouou"));
            CHECK(find(text, "albuuuu") == string("albouou"));
            CHECK(find(text, "albooou") == string("albouou"));
            CHECK(find(text, "albuuuo") == string("albouou"));
            CHECK(find(text, "ooouo") == string("oouuo"));
            CHECK(find(text, "uuuuo") == string("oouuo"));
            CHECK(find(text, "uuuuu") == string("oouuo"));
            CHECK(find(text, "ooooo") == string("oouuo"));

}
TEST_CASE("Test replacement of i and y") {
    string text = "biyy iyii yyi";
            CHECK(find(text, "biii") == string("biyy"));
            CHECK(find(text, "byii") == string("biyy"));
            CHECK(find(text, "byyy") == string("biyy"));
            CHECK(find(text, "iiii") == string("iyii"));
            CHECK(find(text, "yyyy") == string("iyii"));
            CHECK(find(text, "yyii") == string("iyii"));
            CHECK(find(text, "iyyi") == string("iyii"));
}