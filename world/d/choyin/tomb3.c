// Room: /d/choyin/tomb3.c

inherit ROOM;

void create()
{
	set("short", "�������ڲ�");
	set("long", @LONG
�������������������ڲ���������������ŵ�һ��Ũ����̴�㣬��
�ֵ��ǣ���ô���������̴ľ��ȴ��֪�����ζ�������������ϵĳ���
ͨ����������һ�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"tomb1",
	]));
	set("objects", ([
		__DIR__"obj/chest": 1
	]) );

	setup();
	replace_program(ROOM);
}
