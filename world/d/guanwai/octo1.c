
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
  "north" : __DIR__"octostreet",
  "south" : __DIR__"octo2",
  "east" : __DIR__"inn",
  "west" : __DIR__"yizhan",
]));
        set("outdoors", "guanwai");
        setup();
        replace_program(ROOM);

}

