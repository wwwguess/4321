// Room:wg3.c
//write by lysh
inherit ROOM;

void create()
{

	set("short", "���䳡");
	set("long", @LONG
�����Ǿ�����ݵ����䳡����ݵĹ����������׼ҵ��ӣ�
������һ�����������ܹ��������̵��ӣ������˴�����͵��
һЩ����ľ�ˣ����������������������д����ֹ������
�Ƚ��Ľ�����------����ľ�ˡ�

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
 present("jian qian kai",find_object(__DIR__"wgm3"))->set_temp("����/mark",0);

 return ::valid_leave(me, dir);   
}
