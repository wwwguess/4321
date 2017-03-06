// Room: /d/choyin/n_gate.c

inherit ROOM;

void create()
{
	set("short", "�����سǱ���");
	set("long", @LONG
���������سǵı��ţ�һ���ߴ��ʯ��¥������������š�������
�֣�һ������·��������һƬ���֣���������ͨ�����ߵ�ɽ�ϣ�ʯ��
¥�Զ�����ֻʯʨ�����������س������ֵĻ���������Զ�ڳ��ϣ����
������һ�������ԵñȽ����壬�͸��������һ����������ӡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north"  : __DIR__"liulin",
		"south" : __DIR__"n_street1",
//	"east" : "/d/social_guild/gee/gee_room",
	]));
	set("objects", ([
		__DIR__"npc/cityguard": 2,
		__DIR__"npc/ghost": 1,
		"/obj/npc/garrison": 2,
	]) );
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
