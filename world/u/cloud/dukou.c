// Room: /u/cloud/dukou.c

inherit ROOM;

void create()
{
        set("short", "�����ɿ�");
        set("long", @LONG
���Ǹ���˵����ȴ��������Ķɿڡ�����ȥ��ͨ������������ʯ
������������޷������˵���ˮ�ˡ�������ȥ����Լ�ɼ��԰�����ɽ��
������ɽ����������������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sroad1",
  "south" : __DIR__"sunhill/northriver",
]));

	set("objects", ([
                "/u/cloud/npc/boater" : 1,
	]) );

        set("outdoors", "cloud");

        setup();
}
