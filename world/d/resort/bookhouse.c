inherit ROOM;

void create()
{
        set("short", "藏书阁");
        set("long", @LONG
干干净净的书架上堆满了铁雪山庄的武功秘笈。这些秘笈
是多情刀客铁少和多情剑客雪蕊儿半生心血的结精。
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

        if ( !arg || (arg!="书架") ) return 0;

        me=this_player();
        if ( query_temp("got") ) {
                message_vision("$N在书架上找了找但没找到些什麽\n",me);
                return 1;
        }

        message_vision("$N在书架中找了到一本书\n",me);
        obj=new(__DIR__"obj/book3");
        obj->move(me);
        set_temp("got", 1);
        return 1;
}
