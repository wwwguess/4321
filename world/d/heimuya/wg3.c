// Room:wg3.c
//write by lysh
inherit ROOM;

void create()
{

	set("short", "练武场");
	set("long", @LONG
这里是精武武馆的练武场，武馆的馆主是少林俗家弟子，
这里是一个练武厅，总管体恤本教弟子，特派人从少林偷来
一些少林木人，供弟子练功。所以这里有从少林购入的最
先进的健身器------少林木人。

LONG
	);
       set("exits", ([                                
           "south" : __DIR__"wgm3",                                                                                                                       
	 ]));                                           
               set("objects",([                                                                              
      	  "/d/shaolin/npc/mu-ren.c" : 20,        
	         ])); 

          setup();
}


int valid_leave(object me,string dir)    
{
 present("jian qian kai",find_object(__DIR__"wgm3"))->set_temp("有人/mark",0);

 return ::valid_leave(me, dir);   
}
