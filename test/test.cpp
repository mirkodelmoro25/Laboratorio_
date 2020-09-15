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

//getters, setters test

TEST(iniFileManagerTest, GetterSetterTest) {
    FileIni file("Prova.ini");
    file.setValue("Sezione 1", "Parametro 2", 5);
    ASSERT_EQ(stoi(file.getValue("Sezione 1", "Parametro 2")), 5);
}

TEST(FileIniTest, NumParametersTest) {
FileIni file("Prova.ini");
file.setValueS("Sezione 4", "Parametro 6", "Valore stringa");
file.setValue("Sezione 4", "Parametro 8", 5);
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


TEST(iniFileManagerException, ReadTest) {
    FileIni file("Prova.ini");
    file.read("../FileIni.cpp");
    EXPECT_THROW(file.checkIsOpen(), std::runtime_error);
}
TEST(iniFileManagerException, WriteTest) {
    FileIni file("Prova.ini");
    file.write("../Prova");
    EXPECT_THROW(file.checkIsOpen(), std::runtime_error);
}
