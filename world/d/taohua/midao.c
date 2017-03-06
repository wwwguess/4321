
// Room: /d/new_taohua/midao.c
// Copyright (C) 1997, by Kou Gang. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ROOM;

void create()
{
        set("short", "Ä¹ÖĞÃØÊÒ");
        set("long", @LONG
ÕâÊÇ»ÆÒ©Ê¦Ö®ÆŞµÄÄ¹ÖĞµÄÃØÊÒ£¬ÕıÃæÊÇÊÇÒ»ÕÅ¹©×À£¬×ÀÉÏ°Ú·Å×ÅËıµÄÁéÅÆ¡£
Á½²àÊÇÒ»Ğ©Ñ³ÔáµÄ±¦Îï¡£×îÒıÈË×¢Ä¿µÄÊÇÒ»±¾Êé£¬ÉÏĞ´¡°¾ÅÒõÕæ¾­¡±ËÄ×Ö¡£
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "out" : __DIR__"muxue",
        ]));
        set("item_desc", ([
                "book": "Õâ±¾ÊéÉÏµÄ×ÖÊÇÓÃÕë´ÌÔÚÈËÆ¤ÉÏµÄ£¬Äã¿É½«ËüÊ°Æğ£¨pick£©¡£\
n",
                "¾ÅÒõÕæ¾­": "Õâ±¾ÊéÉÏµÄ×ÖÊÇÓÃÕë´ÌÔÚÈËÆ¤ÉÏµÄ£¬Äã¿É½«ËüÊ°Æğ£¨pick£
©¡£\n"
        ]) );

        setup();
}
 void init()
{
        add_action("do_love","pick");
}
int do_love(string arg)
{
        object me,book;
        me=this_player();
        if(!arg )
                return notify_fail("pick <¶«Î÷>\n");
        if(query_temp("mark/been_get")) return notify_fail("ÊéÒÑ±»ÄÃ×ßÁË¡£\n");
        if((arg == "book"||arg == "¾ÅÒõÕæ¾­") && me->query_skill("qimen-bagua",1
)>60) {
                        message_vision( "\n$N½«ÊéÄÃÁËÆğÀ´¡£\n",this_player());
                        book=new(__DIR__"obj/ninebook");
                        book->move(me); 
			me->set("marks/ninebook",1);
                        set_temp("mark/been_get",1);
                        return 1;
                }
        message_vision( "\nÃØÊÒÖĞµÄ»ú¹ØÍ»È»·¢¶¯,½«$N¼·³ÉÁËÒ»Ì²ÈâÄà¡£\n",this_player());
        me->die();
        return 1;
}
void reset()
{
    ::reset();
        delete_temp("mark/been_get");
    if(query("exits/enter"))
        delete("exits/enter");
}
