// Room: /d/snow/postoffice.c

inherit ROOM;

void create()
{
	set("short", "��վ");
	set("long", @LONG
�����Ǹ���ٸ������������������վ�����յ��ż�Ҳ����ͨ�������վ
���д��ݡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"dchjie1",
	]));
	set("objects", ([
		"/d/jingcheng/npc/daizong": 1,
	]) );

	setup();
}

int valid_leave(object me, string dir)
{
	object mbox;

	if( mbox = me->query_temp("mbox_ob") ) {
		tell_object(me, "�㽫���佻����վ��\n");
		destruct(mbox);
	}
	return 1;
}
