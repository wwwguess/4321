// Room: /d/new_taohua/shufang.c

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
����������Ŀ,ȫ��ʫ��伮���������ϰ������ͭ�����󣬿�����
�ǹ�����Ϲ���һ��ˮī����������һ����������������֮ҹ��ͥ������
�ְ����������쳤̾�������į��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "west" : __DIR__"yonglu7",
  "north" :__DIR__"huangwshi",
  "south" :__DIR__"yinyueshi",
]));
	

	setup();
	replace_program(ROOM);
}
