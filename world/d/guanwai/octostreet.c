
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
  "west" : __DIR__"dazhaotemple",
  "east" : __DIR__"citygate",
  "north" : __DIR__"octo16",
  "south" : __DIR__"octo1",
]));
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"npc/lama" : 3,
                __DIR__"npc/traveller": 4,
        ]) );
        setup();
}

