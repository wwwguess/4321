
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������ϳ��ţ��ߴ�ĳ���ʹ�㲻����̾�ⲻ���Ǿų��ʶ���������
���ǲ��ܹ������룬����ĵ�����������������㲻��ȥ��һ�����̣�������
��ĵ��԰�У�������ĵ������һ����ż�����ɵľ���������һ����Ȥ�����⣬
����ʯ�ߡ����ֺͰ�����Ҳ���ܲ�ȥ��˵�������������ľ�ϲ��

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" : "/d/road/rlytotg0",
	"east" : "/d/road/rjdtoly4",
	"south" : "/d/road/rlytoxy0",
]));

	setup();
	replace_program(ROOM);
}
