// Room: /d/sanyen/drag_field.c

inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
һƬ������ҩ��, ҩ����Ǵ�����ɢ�������ġ������ƺ�������
ϸ�Ĺ滮, һ��һ���, �ı��ֵ���, �ı������, ���������һ��
��ֻ�ǿ�����ȥ��ֻ��ЩѰ����ҩ��, �������Ƚ��������ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
            "west" : "/d/sanyen/road2",
]));
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
