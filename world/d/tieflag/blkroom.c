#include <room.h>  
inherit ROOM;
void create()
{
  set("short","ʯ��");
  set("long",@LONG
��ֻ��һ�������ߵ�ʯ����ʯ����ͷ��һƬ�ز�������ˮ����������Լ������
LONG
  );
  	set("exits/center" ,__DIR__"shishi");
  	set("exits/north"  ,__DIR__"outboat");
    setup();
 }
                  