// Room: /d/quanzhou/xijie.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������Ȫ�ݵ�����֣�������һ���ưܵ�լ�ӡ�������һ���ӻ��̣�
ר��Ů�˼��õĶ��������˲����Խ�ȥ���������Ǿ޾�����ܶ档
LONG
        );

        set("exits", ([
                "east" : __DIR__"zhongxin",
                "south" : __DIR__"jujing-bang",
                "north" : __DIR__"laozhai",
                "west" : __DIR__"zahuopu",
        ]));

        set("outdoors", "quanzhou");
        setup();
}

int valid_leave(object me, string dir)
{

	if ( me->query_temp("riden") && dir == "north")
		return notify_fail("����ط����������ȥ��\n");
	if ( !userp(me) && dir == "north" )
			return 0;

        if (dir == "west" && ((string)me->query("gender") =="����") && !wizardp(
me))
                return notify_fail("�������ү�Ƕ�ȥ�Ǹ����\n");
        return 1;
}
