
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
  "west" : __DIR__"citygate",
  "east" : __DIR__"grassland3",
]));
        set("outdoors", "guanwai");

        setup();
        replace_program(ROOM);
}

