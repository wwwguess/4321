// Room: /d/choyin/altar.c

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
������Ƿ�����������Ĵ����������ߴ����������(statue)
�����������ǰ���Ա߻��л��������Ĳ���������ӥ��λ������������
��վ�ĵط��Ǻ���ֵ�������һ����̨���������˿��Կ�������Ľֵ�
������Ϣ����Ⱥ���ϱ�����һ���������»ص��ֵ���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"dragon_temple",
]));
	set("no_fight", "1");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"obj/denotation" : 1,
		__DIR__"npc/lady" : 1,
]));
	set("no_clean_up", 0);
	set("no_magic", "1");
	set("valid_startroom", "1");

	setup();
	replace_program(ROOM);
}
