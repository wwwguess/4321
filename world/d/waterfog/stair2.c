// Room: /d/waterfog/stair2.c

inherit ROOM;

void create()
{
	set("short", "��ʯ����");
	set("long", @LONG
������������һ�������İ�ʯ�����ϣ���Щ������ݵİ�ʯ������
����������ƿɽ������˵��н�ǧ��֮ң��������Ȼ�����Զ����Ȼ��
�Կ��ó����õ�ȫ������Ʒ����õġ�����ʯ���ɼ���������˱ض�
������ͷ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : "/d/waterfog/stair1",
  "eastup" : "/d/waterfog/stair3",
]));
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
