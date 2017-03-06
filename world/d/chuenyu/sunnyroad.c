// Room: /d/chuenyu/sunnyroad.c

inherit ROOM;

void create()
{
	set("short", "ɽ������");
	set("long", @LONG
���������ïʢ�ĵ������һ���峺���׵�СϪ���������������
�����æµ�š��ٱ����Ǻ���ɽ������ɽ�������ƺ����Կ���һ���ľ߹�
ģ�ĳǱ����Ǳ�����˲���һ����죬������������������Ľ��֣����ڡ�
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/flower_seller" : 1,
]));
	set("no_magic", 1);
	set("outdoors", "chuenyu");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"base_b_m",
  //"south" : __DIR__"dustyroad3",
  "southwest" : __DIR__"croad2",
]));
	set("no_fight", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
