// ywgu2.c
//by dwolf  
  
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"ҩ����"NOR);
	set("long", @LONG
	   ������ҩ���ӣ�ֻ��һ��������������ϯ�����񣬼������ˣ�����΢΢
һЦ��վ������������û��ʲô��Ķ�������֪ҩ����ʲô������������
LONG
	);

	set("exits", ([
		"out" : __DIR__"ywgu.c", 
	 ]));  
	set("objects", ([
		__DIR__"npc/yaow" : 1,
	]));
	setup();
}            
           