// Room: /d/choyin/sw_road1.c

inherit ROOM;

void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
����һ�����������Ľֵ�������������ͨ���˳����������Ź㳡��
��һ��ԭ�����������سǵľ�����֮�⣬�����Ȼ����Ũ��������Ϣ
��������һ��С·������������ͨ���������ϰ����ֵ�����ͨ��������
����������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"northeast" : __DIR__"s_street1",
		"west" : __DIR__"dragon_temple",
]));
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
