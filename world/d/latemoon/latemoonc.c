inherit ROOM;

void create()
{
    set("short","������Ժ");
	set("long", @LONG
��������ׯ���ССͥԺ������ƺ����󣬵���ľ���裬��Ŀ������
������������÷������Լ���㣬����һ����ζ�����������÷�����е�
���������ڷ���.....
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "north" :__DIR__"latemoon5",
    "west" :__DIR__"latemoon7",
    "east" :__DIR__"latemoon1",
    "south" :__DIR__"latemoon4"

]));

	setup();
	replace_program(ROOM);
}
