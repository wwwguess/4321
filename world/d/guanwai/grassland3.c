
inherit ROOM;

void create()
{
        set("short", "��ԭ");
        set("long", @LONG
������һ���޼ʵĴ��ԭ����ɫ�Ĳݵ������þ������ʵ����졣��ԭ��
������������Ⱥ����������Ʈ���Ķ����ơ�Զ���Ĳ��������ڽ����¿���
���紿��������Ϧ������ʱ�ֱ�ò�����ƽ���Ҳ���û�뵽���������
����֮�ؾ����������ĵط������ûԻͶ����أ����������Ի���������
�����ˡ�
LONG
        );
        set("exits", ([ 
  "northeast" : "/d/road/rlstotgl0",
  "west" : __DIR__"grassland4",
  "east" : __DIR__"grassland2",
]));
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"npc/sheepgirl3" : 3,
		__DIR__"npc/sheep3" : 6,
        ]) );
        setup();
}

