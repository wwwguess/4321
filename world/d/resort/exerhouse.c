inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�ɸɾ�����ǽ�Ϲ���һ���ֻ�������д����֪ɽ��·��Ϊ����
ѧ�����Ŀ����ۡ������ϴ�ɨ��һ����Ⱦ��ǽ�Ƕ��źܶ��񵶽���
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"back_yard",
]));

       set("objects", ([
                __DIR__"obj/bsword" : 3,
                __DIR__"obj/bblade" : 4,
                __DIR__"obj/pieces" : 3,

        ]) );

        setup();
}

void init()
{
        add_action("do_gets", "get");
}

int do_gets(string arg)
{
        if(arg == "all")
        {
                write("��̫̰���ˡ�\n");
                return 1;
        }
        else
                return 0;
}
