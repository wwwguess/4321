inherit ROOM;

void create()
{
    set("short", "�߷���");
	set("long", @LONG
����������ǰ����ˮ�羧��һ�㱼�룬����������ȥ��ֻ��ˮ
���仨���࣬��ˮ���壬���ܵ����������������ر����д�������
���ҡ��ӣ�������հ㣬����һЩ�������ȹ���ȥ��ͨ������ͤ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "north" :__DIR__"moonc",
       "south" :__DIR__"pavilion1",

]));

	setup();
	replace_program(ROOM);
}
