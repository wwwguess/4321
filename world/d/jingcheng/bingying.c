#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"����Ӫ"NOR);
	set("long", @LONG
�����Ǳ�Ӫ���������ǹٱ�������ȥ���е����佫��ָ�����жӲ�
�����еĶ������������е����š�����������Ϣ����������������
������˧��������ɫ��Ѱ�������ܡ�
LONG         
	);

	set("exits", ([ 
 "south" :__DIR__"dchjie4", 
 
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

