//
// Created by mirko25 on 09/09/20.
//

#include "/home/mirko25/CLionProjects/Laboratorio_/FileIni.cpp"
#include "/home/mirko25/CLionProjects/Laboratorio_/FileIni.h"
#include "/home/mirko25/CLionProjects/Laboratorio_/test/lib/googletest/include/gtest/gtest.h"

//constructor tester
TEST(FileIniTest, ConstructorTest) {
FileIni constructorTester("iniFile.ini");
ASSERT_EQ(constructorTester.getFileName(), "iniFile.ini");
}

//getters, setters tests
TEST(FileIniTest, StringGetterSetterTest) {
FileIni file("Prova.ini");
file.setStringValue("Sezione 1", "Parametro 1", "valore 1");
ASSERT_EQ(file.getValue("Sezione 1", "Parametro 1"), "valore 1");
}

TEST(FileIniTest, IntGetterSetterTest) {
    FileIni file("Prova.ini");
    file.setIntValue("Sezione 1", "Parametro 2", 5);
    ASSERT_EQ(stoi(file.getValue("Sezione 1", "Parametro 2")), 5);
}

TEST(FileIniTest, FloatGetterSetterTest) {
    FileIni file("Prova.ini");
    file.setFloatValue("Sezione 2", "Parametro 1", 5.98);
    ASSERT_TRUE(abs(stof(file.getValue("Sezione 2", "Parametro 1")) - 5.98) < 0.0001);
}


TEST(FileIniTest, BoolGetterSetterTest) {
FileIni file("Prova.ini");
file.setBoolValue("Sezione 3", "Parametro 1", false);
ASSERT_EQ(file.getValue("Sezione 3", "Parametro 1"), "false");
}

TEST(FileIniTest, NumParametersTest) {
FileIni file("Prova.ini");
file.setStringValue("Sezione 4", "Parametro 6", "Valore stringa");
file.setIntValue("Sezione 4", "Parametro 8", 5);
ASSERT_EQ(file.numbersOfParameters("Sezione 4"), 2);
}

TEST(FileIniTest, addCommentTest) {
FileIni file("Prova.ini");
file.addSection("Sezione 1");
file.addComments("Sezione 1", "commento nella sezione", true);
file.addComments("nessuna sezione", "commento fuori sezione", false);
ASSERT_EQ(file.getValue("Sezione 1", "1"), ";commento nella sezione");
}

TEST(FileIniTest, SectionsTest) {
FileIni file("Prova.ini");
file.addSection("Sezione prova rimozione");
file.removeSection("Sezione prova rimozione");
ASSERT_EQ(file.findSection("Seconda prova rimozione"), false);
}

TEST(FileIniTest, ParameterTest) {
FileIni file("Prova.ini");
file.addParameter("Sezione", "Parametro");
file.removeParameter("Sezione", "Parametro");
ASSERT_EQ(file.findParameter("Sezione", "Parametro"), false);
}

TEST(iniFileManagerException, ParameterTestFail) {
FileIni file("Prova.ini");
file.addParameter("Sezione", "Parametro");
EXPECT_THROW(file.removeParameter("Sezione", "Parametro 2"), std::runtime_error);
}

TEST(iniFileManagerException, SectionsTestFail) {
FileIni file("Prova.ini");
file.addSection("Sezione prova rimozione");
EXPECT_THROW(file.removeSection("Sezione prova rimozione 2"), std::runtime_error);
}


TEST(iniFileManagerException, IsOpenTest) {
FileIni file("Prova.ini");
file.end();
EXPECT_THROW(file.checkIsOpen(), std::runtime_error);
}