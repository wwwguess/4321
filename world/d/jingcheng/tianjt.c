#include <ansi.h>
inherit ROOM;

void create()
{
      	set("short", HIW"�ƾٿ���"NOR);
	set("long", @LONG
������Ǿ������������¼࿼�Ŀ�������͢ÿ��Ŀƾٶ���
������С�����㳡��վ�����࣬��Χ����һЩ������
LONG         
	);    
	set("no_beg",1); 
      	set("no_fight", 1);
    	set("no_sleep_room",1);           
	set("objects",([

		__DIR__"npc/liubw" :1,

          ]));

	set("exits", ([ 
		 "south" :__DIR__"xw5",
 	]));
	setup();
	
}

