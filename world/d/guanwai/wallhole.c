
inherit ROOM;

void create()
{
        set("short", "���ʯ��");
        set("long", @LONG
�����ڴ������ұ��ϵ�ʯ�ߡ�������һ��ɫ�����޵�ȴ�ֲ�֮���ıڻ���
������һ�������������ɲ��Ů������˱��һ�����˵����衣����ϸ�µĻ���
��������������
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"woodhouse",
  "south" : __DIR__"templeyard",
]));
        setup();
        replace_program(ROOM);

}

