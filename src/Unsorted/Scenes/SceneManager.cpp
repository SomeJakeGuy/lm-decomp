#include "Unsorted/SceneManager.hpp"
#include "Unsorted/TitleScene.hpp"

Scene* SceneManager::sSceneTable[SCENE_MAX] = {
    &TitleScene::sTitleScene,
}; 

u16 SceneManager::fn_8000B328() {
    return sCurrScene->_10;
}
