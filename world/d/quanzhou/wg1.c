// Room:wg1.c
//write by lysh
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǿ��������Ȫ�ݵ�����������ݵĹ���������
�׼ҵ��ӣ����������д����ֹ�������Ƚ��Ľ�����
------����ľ�ˡ�

LONG
	);
       set("exits", ([                                
           "south" : __DIR__"wgm1",                                                                                                                       
	 ]));
       	set("objects", ([
		"/d/shaolin/npc/mu-ren": 20,
	]) );
                                  

          setup();
}



int valid_leave(object me,string dir)    
{
 
 present("wang er ma",find_object(__DIR__"wgm1"))->set_temp("����/mark",0);

 return ::valid_leave(me, dir);   
}
