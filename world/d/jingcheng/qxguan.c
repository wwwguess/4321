#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"�����"NOR);
	set("long", @LONG
������Ǿ���������һ�����ۡ������Ƴ��Ļʵۺ�����ͬ�գ�
��˵��̱���Ϊ�Ƴ��Ĺ��̡������ڷ�̵Ĵ��룬���̵�״����
�������ǰ����������û�м������ˡ�
LONG         
	);

	set("exits", ([ 
 "north" :__DIR__"zhq2",
	]));
	setup();
	replace_program(ROOM);
}

