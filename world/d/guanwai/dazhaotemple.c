
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������ʮ�ɣ���һ�ٶ�ʮ�ɡ��������ѵ���ܦ��������ɽ���ϵĳǱ���
���ϵ���Ժ�����������١�¥���㲻��Ĵ��������������������ͣ���
�����ξ����������񻰡�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"octostreet",
  "west" : __DIR__"templeyard",
]));
        set("outdoors", "guanwai");
        setup();
        replace_program(ROOM);

}

