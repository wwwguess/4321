// Room: /d/canyon/stone_forest1.c

inherit ROOM;

void create()
{
	set("short", "��ʯ����··��");
	set("long", @LONG
������һ�����ֵأ��ݸ�������ʮ�ߣ��ټ�����ää�ľ���
ʹ�㲻�ò�������ʯ�̳ɵ�С·�첽���ߣ�����ֲ�ѹ������ʱ����
֪���룬�������ƺ���һ���صĹ�����������̫Զ���㿴�������
������ô��һ���¡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"canyon2",
		"west" : __DIR__"stone_forest2",
]));
	set("shorst", "��ʯ����··��");

	setup();
	replace_program(ROOM);
}
