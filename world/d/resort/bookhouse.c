inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�ɸɾ���������϶�������ѩɽׯ���书���š���Щ����
�Ƕ��鵶�����ٺͶ��齣��ѩ���������Ѫ�Ľᾫ��
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"back_yard",
]));

       set("objects", ([
                __DIR__"obj/book1" : 1,
                __DIR__"obj/book2" : 1,
//                __DIR__"obj/book3" : 1,
                __DIR__"obj/book4" : 1,
                __DIR__"obj/book5" : 1,
                __DIR__"obj/book6" : 1,

        ]) );

        setup();
}
void init()
{
        add_action("search_case","search");
}
int search_case(string arg)
{
        object me,obj;

        if ( !arg || (arg!="���") ) return 0;

        me=this_player();
        if ( query_temp("got") ) {
                message_vision("$N������������ҵ�û�ҵ�Щʲ��\n",me);
                return 1;
        }

        message_vision("$N����������˵�һ����\n",me);
        obj=new(__DIR__"obj/book3");
        obj->move(me);
        set_temp("got", 1);
        return 1;
}
