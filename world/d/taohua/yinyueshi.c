// Room: /d/new_taohua/yinyueshi.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǻ�ҩʦ���������ĵط�������������һ�����ӣ�����
�����˸��ָ�������������������������Ǹ���Ŷ��յ��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "north": __DIR__"shufang",
  
]));
	

	setup();
	replace_program(ROOM);
}
