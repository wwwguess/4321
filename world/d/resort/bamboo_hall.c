inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����������СС�Ĵ����ݡ����м������еļҾ߶�������
���ɵġ����е����Ϸ���һ���������ɰ��ߡ���ѩɽׯ����
Ů��������Ʒ�����塣
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"front_yard",
  "north" : __DIR__"back_yard",
]));
       set("objects", ([
                CLASS_D("resort") + "/master" : 1,
                CLASS_D("resort") + "/master2" : 1,
                __DIR__"npc/girl" : 1,
        ]) );
        set("valid_startroom", 1);
        setup();
}
