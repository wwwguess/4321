// Room: /d/sanyen/corridor1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������һ��������, ���Էֱ�����������������ǽ, ǽ�ϻ�
����ȴ󱯹����������ȿ���ѵ��¼���������������������, ����
�ľ���һ���൱��ķ��ݡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"kitchen",
  "east" : __DIR__"corridor",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
