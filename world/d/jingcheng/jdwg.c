#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"�������"NOR);
	set("long", @LONG
��������վ��һ��������ݵĽ������У��������Ż�ɫ��ϸɰ��һ
Ⱥ��ʮ�������������������Ŭ���ز�����, ����һ�����꺺����
��ͣ�ĺ��ź��ӣ�������ܡ�
LONG         
	);

	set("exits", ([ 
 "south" :__DIR__"xw6",
 	]));
	setup();
	
}

