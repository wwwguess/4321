
inherit ROOM;

void create()
{
        set("short", "ľ��");
        set("long", @LONG
ľ������������бڵ�ľ��ȴ�Ѻܳ¾ɣ��е������Ѹ��ѣ������Ƕ�����
�����ݡ�����ֻ��һ�ŵͰ���ľ����һ���޴�Ļ��衣
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"wallhole",
]));
        set("objects", ([
                __DIR__"npc/yansong" : 1,
        ]) );

        setup();

}

