#ifndef C_PART_H
#define C_PART_H

//****************************************************************************************************
//класс кусочка карты
//****************************************************************************************************

//****************************************************************************************************
//подключаемые библиотеки
//****************************************************************************************************
#include <stdint.h>
#include <fstream>
#include <memory>
#include <list>
#include "ctilessequence.h"
#include "ipart.h"


//****************************************************************************************************
//макроопределения
//****************************************************************************************************

//****************************************************************************************************
//константы
//****************************************************************************************************

//****************************************************************************************************
//предварительные объявления
//****************************************************************************************************

//****************************************************************************************************
//класс кусочка карты
//****************************************************************************************************
class CPart:public IPart
{
 public:
  //-перечисления---------------------------------------------------------------------------------------
  //-структуры------------------------------------------------------------------------------------------
  //-константы------------------------------------------------------------------------------------------
  //-переменные-----------------------------------------------------------------------------------------
 private:
  //-константы------------------------------------------------------------------------------------------
  //-переменные-----------------------------------------------------------------------------------------
 public:
  //-конструктор----------------------------------------------------------------------------------------
  CPart(int32_t block_x=0,int32_t block_y=0,const CTilesSequence &cTilesSequence_Set=CTilesSequence(),bool barrier=false,bool first_plane=false,bool before_background=false,const std::string &name="");
  //-деструктор-----------------------------------------------------------------------------------------
  ~CPart();
 public:
  //-открытые функции-----------------------------------------------------------------------------------
  bool Save(std::ofstream &file);//записать
  bool Load(std::ifstream &file);//сохранить
  bool Export(std::ofstream &file,int32_t scale_x,int32_t scale_y);//экспортировать
  void Release(void);//удалить все элементы
  void AnimationTiles(void);//выполнить анимацию тайлов
  void AnimationTilesByForce(void);//выполнить анимацию тайлов принудительно
  void SetTilesAnimationFrame(size_t frame);//задать кадр анимации
  void Visit(std::function<void(std::shared_ptr<IPart>)> callback_function);//обойти все элементы
  void RemovePart(std::function<bool(std::shared_ptr<IPart>)> callback_function);//удалить часть
  std::list<std::shared_ptr<IPart> >* GetItemPtr(void);//получить указатель на список элементов
  void PushInventory(void);//поместить предмет в инвентарь
  void PopInventory(void);//забрать предмет из инвентаря
  void Enable(void);//разрешить использование предмета
  void Disable(void);//запретить использование предмета
 private:
  //-закрытые функции-----------------------------------------------------------------------------------  
};

#endif