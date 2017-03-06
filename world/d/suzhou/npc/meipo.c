//NPC:/d/suzhou/npc/meipo.c
//changed by dwolf
//97.11.4

#include <ansi.h> 
inherit NPC;

string marry();
string unmarry();

void create()
{
	set_name(RED "媒婆" NOR, ({ "meipo" }) );
	set("title", RED "红娘庄" NOR);
        set("gender", "女性" );
        set("age", 53);
        set("long",
                "一位精明能干的老媒婆\n");
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("inquiry", ([
                "婚约" : MAG"是啊... 这里就可以缔结和解除婚约"NOR,
        ]) );
        set_skill("literate", 70);
        set_skill("dodge", 500);
        set_skill("unarmed", 300);
        setup();
        add_money("gold", 5);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_marry", "marry");
        add_action("do_unmarry", "unmarry");
}

int do_marry(string arg) {
        object marry_card1,marry_card2, obj, me;
		  object ob;
        string target,cardname;
        int i, have_marry;

        me = this_player();

		  if(!arg || !objectp(obj = present(arg, environment(me)))
                || !find_player(arg) )
                return notify_fail("你想和谁缔结良缘？\n");

		  if (marry_card1=present("marrycard",me))
			 { cardname=marry_card1->query("name");
				if (sscanf(cardname,"你和%s的婚约",target)!=1)
					{destruct(marry_card1);
					};
				if (target!=obj->query("id"))
			       return notify_fail(
                "你已经和别人有婚约了吧?这里不允许重婚的。\n");
          }

       if (present("marrycard",obj))
                return notify_fail(
               "你的对象已经和别人有婚约了吧?这里不允许重婚的。\n");

        if( !environment()
        ||      base_name(environment()) != query("startroom") )
             return notify_fail(
                "真是抱歉，请您等一下到红娘庄来找我吧。\n");


        if( !living(obj) )
                return notify_fail(obj->name() + 
                "已经无法和你缔结良缘了。\n"); 

        if(obj==me)     return notify_fail("你不能和自己缔结婚约。\n");

        if((string)obj->query("gender")== (string)me->query("gender"))
                return notify_fail("你不怕" + RED"AIDS"NOR + "吗？\n");

        if( (string)me->query("class")=="bonze" )
                return notify_fail("和尚怎么能结婚呢？？？\n");


        if ( (((int)me->query("age")<17)&&
                ((string)me->query("gender")=="男性")) ||
              (((int)me->query("age")<14) &&
                ((string)me->query("gender")=="女性")) )
                return notify_fail("你太小啦，怎么可以啦？\n");  

        if( userp(obj) && !((object)obj->query("marks/"+me->name(1)+"_m"))){
                message_vision(MAG "\n$N对著$n说道：" 
                    + RANK_D->query_self(me) 
                    + me->name() + "，愿意和"
                    + RANK_D->query_respect(obj) + 
                "结为夫妇\n\n"NOR, me,obj);           
        if( me->query("marks/"+obj->name(1)) ) {
                tell_object(obj, YEL + me->name() + 
                    "取消了和你结婚的念头。\n" NOR);
                me->set("marks/"+obj->name(1)+"_m", 0);
        }
                 me->set("marks/"+obj->name(1)+"_m", 1);
           tell_object(obj, MAG "如果你愿意和对方结为夫妇，请你也对" 
                        +me->name() + "("+(string)me->query("id")+
                        ")"+ "下一次 marry 指令。\n" NOR);
                write(MAG  
                        "现在你急切盼望着你的心上人说同意...\n" NOR);
                return 1;
        }
        
		  if (!(marry_card1=present("marrycard",me)))
           marry_card1 = new("/obj/misc/marry_card");
        marry_card1->set("name","你和"+obj->query("id")+"的婚约");
        marry_card1->move(me);
        if (!(marry_card2=present("marrycard",obj)))
           marry_card2 = new("/obj/misc/marry_card");
        marry_card2->set("name","你和"+me->query("id")+"的婚约");
        marry_card2->move(obj);
	me->set("is_married", 1);
   obj->set("is_married", 1);
        
        message_vision(MAG "恭喜 $N 和 $n ，一对璧人喜结良缘。\n" NOR,
        obj, me);
        message("chat", me->name() + "和" + obj->name() + 
        "现在开始是夫妇啦\n", environment(me),me); 
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s 和 %s 现在开始是夫妇啦! \n", 
        me->name(1), obj->name(1)));


        return 1;
}

int do_unmarry(string arg)
{
        object marry_card1,marry_card2,  me;
        object couple_ob;
        int i, have_marry;
        string target, tmpstr1, tmpstr2,str1,str2;
        string cardname;
             
        me = this_player();       
        have_marry = 0;
        if (marry_card1 = present("marrycard",me)) 
                have_marry = 1;

        if (have_marry == 0)
                return notify_fail("你还未有婚约啊。\n");
        
        cardname = marry_card1->query("name");
        
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
           return notify_fail("真是抱歉，请您等一下到红娘庄来找我吧。\n");
		  if (sscanf(cardname,"你和%s的婚约" ,target)!=1)
                return notify_fail("你没有伴侣.\n");

         if(!objectp(couple_ob = present(target, environment(me)))
                || !find_player(target) )
                return notify_fail("你的伴侣现在不在场.\n");

        if ((string)couple_ob->query("gender") != "女性") {
                tmpstr1 = "老婆"; tmpstr2 = "老公";
                str1 = "她"; str2 = "他";
        } else {
                tmpstr1 = "老公"; tmpstr2 = "老婆";
                str1 = "他"; str2 = "她";
        }

        have_marry = 0;
        if (marry_card2 = present("marrycard", couple_ob))
                have_marry = 1;

        if (have_marry = 0) {
                destruct(marry_card1);                  

        message_vision(MAG " $N 和 $n 从现在开始解除婚约,互不相干!\n" NOR,
        couple_ob, me);
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s 和 %s 从现在开始解除婚约,互不相干! \n",
        me->name(1), couple_ob->name(1)));

                return 1;

        }

        if( userp(couple_ob) && !((object)couple_ob->query("marks/"
                + "unmarry" +me->name(1))) ) {
                message_vision(MAG "\n$N对著$n说道：" 
                        + RANK_D->query_self(me) 
                        + me->name() + "，咱们解除婚约吧!好吗?\n\n"
                        NOR, me, couple_ob);           
                 me->set("marks/"+"unmarry"+couple_ob->name(1), 1);
           tell_object(couple_ob, MAG "如果你愿意解除婚约，请你也"
                + "下一次 unmarry 指令。\n" NOR);
                write(MAG  
                "现在你只有等着" +str2 +" 同意啦...\n" NOR);
                return 1;
        }

		  destruct(marry_card1);
        destruct(marry_card2);
        
        message_vision(MAG " $N 和 $n 从现在开始解除婚约,互不相干!\n" NOR,
        couple_ob, me);
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s 和 %s 从现在开始解除婚约,互不相干! \n", 
        me->name(1), couple_ob->name(1)));

        return 1;
}
