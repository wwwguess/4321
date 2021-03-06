//yangdingtian room

inherit ROOM;

void create()
{
        set("short", "石室");
        set("long", @LONG
    这是一间极大的石室，顶上垂下钟乳，显然是天然的石洞。地下倒着两具骷髅，
骷髅身上衣服尚未烂尽，看得出是一男一女。
LONG
        );

        set("exit", ([
        ]));
        set("item_desc", ([
		"骷髅" : "男骷髅的手旁好像有封信。\n" ,
	    "skeleton" : "男骷髅的手旁好像有封信。\n"
	]));
        setup();
}

void init()
{
        add_action("do_pick","pick");
        add_action("do_ketou","ketou");
        add_action("do_move","move");
}

int do_pick(string arg)
{
        object me,letter;
        
        me=this_player();

	if (!arg || arg=="")
		return notify_fail("pick <物件>\n");

        if( arg=="letter" ) 
        {
                message_vision(
		"$N走到那个男子的骷髅之前，随手把信拾了起来。\n", me);
                letter = new(__DIR__"obj/letter");
                letter->move(me);
		return 1;
        }

        return notify_fail("你要拿什么？\n");
}


int do_ketou()
{
        object me,book;

        me = this_player();

        message_vision("$N虔诚地跪下来，在骷髅前磕头。\n", me);
        
        if ((int)me->query("gin")<=50) 
        { 
                tell_object(me,"你太累了，休息一下吧！\n");
                return 1;
        }

        if ( random(20) == 11 )
        {
                book=new(__DIR__"obj/skinbook");
                book->move(me);
                tell_object(me, "突然骷髅哗得一声倒下，露出一本羊皮书!\n");
        }

        me->receive_damage("gin", 50);

        return 1;

}


int do_move(string arg)
{
        
        if( !arg || arg=="" )
		return notify_fail("move <物件>\n");

        if(arg=="无妄")
	{
                if(this_player()->query_skill("qiankun-danuoyi",1)>=10)
        	{
                	message_vision(
"$N运起乾坤大挪移心法，石门便轧轧作响,缓缓地开了。\n", this_player());
                	set("exits/out", __DIR__"midao");

	                remove_call_out("close");
        	        call_out("close", 5, this_object());

	                return 1;
		}

		return notify_fail("你的乾坤大挪移功力不够。\n");

	}
	return notify_fail("你要移动什么？\n");
}

void close(object room)
{
        message("vision","石头移回原地。\n", room);
        room->delete("exits/out");
}
