#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"�׻����"NOR);
	set("long", @LONG
  �׻���ֵ��ϲ��ǳ��������������ֳ������еĵط���·��
��һ��ͨ����Ъ��С�ƹݣ�������ǰ׻���ֺ���ȸ��ֵ�ʮ
��·�ڡ�
LONG         
	);

	set("exits", ([ 
 "south" :__DIR__"zhq7",
 "north" :__DIR__"baih4",
 "east" :__DIR__"jiuguan",  
 "west" :__DIR__"huadian",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

