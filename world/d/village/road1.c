// Room: /d/village/road1.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
������������ܿ������㹻���˼������������������彻սʱ������
���ӴӴ˾�������ƽʱ��ֻ���������������������������ͨ����ʦ������
�����չء�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road2",
  "north" : "/d/canyon/canyon7",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
