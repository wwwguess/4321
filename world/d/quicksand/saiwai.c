inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���Ƶ����ǻ�Ȼ���ʣ����������һ���޼ʵ�ɳĮ������ں����������
ɳ�ڷ��裬��ɳ������ɳ������������ϣ������ǲ��ŭͶ�µı�����ڤڤ
�з·�������а����������κ�����ʱ���п���ͻȻ��Ұ��������ɳ��
�ϡ�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"oldgreatwall",
  "west" : __DIR__"saiwai2",
]));
        set("outdoors", "quicksand");
        set("objects", ([
                __DIR__"npc/trader3" : 2,
        ]) );
        setup();
}
