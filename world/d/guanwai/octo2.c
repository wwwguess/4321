
inherit ROOM;

void create()
{
        set("short", "�˽ǽ�");
        set("long", @LONG
�������⣬Χ������Ժ�İ˽ǽ��ǲ���������������ֵĵط�������
���Ŀ�ջ���̺Ŷ����������ϡ�Զ��������ʱ��������һ���������Ʈ
���������ļⶥ��̫�������Ž�⣬��������ʥׯ�����µľ���
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"octo1",
  "west" : __DIR__"octo3",
]));
        set("outdoors", "guanwai");
        setup();
        replace_program(ROOM);

}

