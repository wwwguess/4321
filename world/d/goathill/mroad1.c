// Room: /d/goathill/mroad1.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������������һ����᫵�ɽ·�ϣ�����͹͹��ɽʯ�̵���Ľŵ���
�����ۣ�ɽ·���ϲ�Զ��ͨ��һ��ɽ����̨�أ���һ����������λ
��̨���ϣ����߸����߶��Ƕ��͵�ɽ�ڣ�ɽ·����ͨ����������Ⱥɽ
֮�С�
LONG
	);
	set("outdoors", "goathill");
  set ("exits", ([ /* sizeof() == 3 */
//		"west" :"/d/hhu/out-hohai",
		"north" : __DIR__"mroad2",
		"south" : "/d/snow/crossroad",
]));

	setup();
	replace_program(ROOM);
}
