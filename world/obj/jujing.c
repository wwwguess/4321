// jujing.c 巨鲸帮帮主 

#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif
#define JUJING NPCDATA + "jujing"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
inherit F_SAVE;

string query_save_file()
{
        return JUJING;
}

void create()
{
        seteuid(getuid());

        if (!restore()) {
    	set_name("沙无霸", ({ "jujing bangzhu", "bangzhu", "zhu" }) );
        set("title", "巨鲸帮帮主" );
        set("gender", "男性" );
        set("age", 30);
      	set("long","他是巨鲸帮的帮主。\n");
        set("attitude", "heroism");
        set("generation",0);
        set("winner","none");

        set("str", 25);
        set("con", 25);
        set("int", 25);
        set("dex", 25);

        set("max_kee", 500);
        set("eff_qi", 500);
        set("kee", 500);
        set("max_gin", 300);
        set("gin", 300);
        set("force", 500);
        set("max_force", 500);
        set("jiali", 40);
        set("shen_type", 0);

        set("no_clean_up",1);
        set("combat_exp", 100000);

        set_skill("force",  100);
        set_skill("unarmed",100);
        set_skill("dodge",  100);
        set_skill("parry",  100);

        set("armor", "/d/city/obj/cloth");

        setup();

        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/city/obj/cloth")->wear();
        }
        else {
                set("id", "jujing");
                set_name(query("name"), ({ query("id") }));
                setup();
                if( this_object()->query("weapon") ) carry_object(this_object()->query("weapon"))->wield();
  		if( this_object()->query("armor") )  carry_object(this_object()->query("armor"))->wear();

        }
}

void init()
{
        object me = this_object();

        add_action("do_recopy",  "recopy");
        add_action("do_recover", "recover");
        add_action("do_kill", "kill");

}

int do_kill()
{
        object ob;
        int i;

        command("say 你想谋害本帮主，当真是吃了熊心豹子胆了！！");
        command("say 小的们！给我上");

        message_vision("四周的帮众群起对$N发动攻击！\n", this_player());

        for(i=0; i<4; i++) {
                if( objectp( ob = present("bang zhong " + (i+1), environment(this_object())) ) )
                                 ob->kill_ob(this_player());
                else    this_object()->kill_ob(this_player());
        }

        return 1;
}

int accept_fight(object ob)
{
       	object me, feilong,heluo,yan,tianjie,gelao,heishou,qingzhu,tiandi,qisha;
        string name1, name2,name3,name4,name5,name6,name7,name8,name9;

        me  = this_object();
        if ((int)this_player()->query_condition("bonze_drug")>0)

        return notify_fail("一年只能挑战一次，你怎么又来捣乱了！！！\n");
        if(!( feilong = find_living("feilong")) )
        feilong = load_object("/clone/npc/feilong");
        name1 = feilong->query("winner");

        if( this_player()->query("id") == name1 )
                return notify_fail("你已经是飞龙帮帮主，还要抢当巨鲸帮主？！\n");

/*        if(!( heluo = find_living("heluo")) )
        heluo = load_object("/clone/npc/heluo");
        name2 = heluo->query("winner");

        if( this_player()->query("id") == name2 )
                return notify_fail("你已经是河洛帮帮主，还要抢当巨鲸帮主？！\n");

        if(!( yan = find_living("yan")) )
        yan = load_object("/clone/npc/yan");
        name3 = yan->query("winner");

        if( this_player()->query("id") == name3 )
                return notify_fail("你已经是盐帮帮主，还要抢当巨鲸帮主？！\n");

        if(!( tianjie = find_living("tianjie")) )
        tianjie = load_object("/clone/npc/tianjie");
        name4 = tianjie->query("winner");

        if( this_player()->query("id") == name4 )
                return notify_fail("你已经是天劫帮帮主，还要抢当巨鲸帮主？！\n");

        if(!( gelao = find_living("gelao")) )
        gelao = load_object("/clone/npc/gelao");
        name5 = gelao->query("winner");

        if( this_player()->query("id") == name5 )
                return notify_fail("你已经是哥老会会长，还要抢当巨鲸帮主？！\n");

        if(!( heishou = find_living("heishou")) )
        heishou = load_object("/clone/npc/heishou");
        name6 = heishou->query("winner");

        if( this_player()->query("id") == name6 )
                return notify_fail("你已经是黑手党书记，还要抢当巨鲸帮主？！\n");

        if(!( qingzhu = find_living("qingzhu")) )
        qingzhu = load_object("/clone/npc/qingzhu");
        name7 = qingzhu->query("winner");

        if( this_player()->query("id") == name7 )
                return notify_fail("你已经是青竹帮帮主，还要抢当巨鲸帮主？！\n");

        if(!( tiandi = find_living("tiandi")) )
        tiandi = load_object("/clone/npc/tiandi");
        name8 = tiandi->query("winner");

        if( this_player()->query("id") == name8 )
                return notify_fail("你已经是天地会会长，还要抢当巨鲸帮主？！\n");

        if(!( qisha = find_living("qisha")) )
        qisha = load_object("/clone/npc/qisha");
        name9 = qisha->query("winner");

        if( this_player()->query("id") == name9 )
                return notify_fail("你已经是七杀帮帮主，还要抢当巨鲸帮主？！\n");
*/
        if ( me->query("winner") == ob->query("id") )
                return notify_fail("你跟你自己打什么架？！\n");

        if (wizardp(this_player()))
                return notify_fail("巫师不能抢帮主之位！\n");

        if ( me->is_fighting() )
                return notify_fail("已经有人正在挑战巨鲸帮主！\n");
          this_player()->apply_condition("bonze_drug", 6000);
 	me->set("eff_qi", me->query("max_kee"));
        me->set("kee",     me->query("max_kee"));
        me->set("gin",   me->query("max_gin"));
        me->set("force",  me->query("max_force"));

        remove_call_out("checking");
        call_out("checking", 1, me, ob);

        return 1;
}

int checking(object me, object ob)
{

        object obj;
        int my_max_qi, his_max_qi;

        my_max_qi  = me->query("max_kee");
        his_max_qi = ob->query("max_kee");

        if (me->is_fighting()) {
                if ( (me->query("kee")*100 / my_max_qi) <= 80 )
                        command("exert recover");

                call_out("checking", 1, me, ob);
                return 1;
        }

        if ( !present(ob, environment()) ) return 1;

        if (( (int)me->query("kee")*100 / my_max_qi) <= 50 ) {
                command("say 果然厉害，恭喜你成为本帮帮主！\n");
                command("chat 哈哈哈，到底是长江後浪推前浪，一代新人换旧人！\n");
                command("chat 恭喜" + ob->query("name") + "被推举为新一任巨鲸帮帮主！\n");
                remove_call_out("do_copy");
                call_out("do_copy", 1, me, ob);
                return 1;
        }

        if (( (int)ob->query("kee")*100 / his_max_qi) < 50 ) {
                command("say 看来" + RANK_D->query_respect(ob) +
                        "还得多加练习，方能在当今武林中出人头地 !\n");
                return 1;
        }

        return 1;
  }

int do_copy(object me, object ob)
{
        object ob1, ob2;
        string bangzhu;

        seteuid(getuid());

        me->set("winner", ob->query("id"));
        me->add("generation", 1);

        me->set("name",  ob->query("name") );
        me->set("title", "第" + chinese_number(me->query("generation")) + "代巨鲸帮帮主");
        me->set("short", me->query("title") + " " + me->query("name") + "(" + capitalize(ob->query("id")) + ")");
        me->delete("title");

	me->set("mud_age", ob->query("mud_age"));
	me->set("shen", ob->query("shen"));
	me->set("luohan_winner", ob->query("luohan_winner"));
	me->set("dai", ob->query("dai"));
	me->set("is_beggar", ob->query("is_beggar"));
	me->set("readed", ob->query("readed"));
	me->set("betrayer", ob->query("betrayer"));

        ob->delete_temp("apply/short");
        ob->set_temp("apply/short", ({me->short()}));

        me->set("title", "第" + chinese_number(me->query("generation")) + "代巨鲸帮帮主");
        me->set("short", me->query("title") + " " + me->query("name") + "(jujing bangzhu)");
        me->delete("title");

        remove_call_out("do_clone");
        call_out("do_clone", 0, me, ob);

        return 1;
}

int do_recopy(object me, object ob)
{
        me = this_object();
        ob = this_player();

        if ( me->query("winner") != ob->query("id") )
                return notify_fail("你不是现任巨鲸帮主！\n");;

	if ( me->query("mud_age") > ob->query("mud_age"))
                return notify_fail("你想用 bug 谋利，呵呵！\n");

        me->set("name",  ob->query("name") );
        me->set("title", "第" + chinese_number(me->query("generation")) + "代巨鲸帮帮主");
        me->set("short", me->query("title") + " " + me->query("name") + "(" + capitalize(ob->query("id")) + ")");
        me->delete("title");

	me->set("mud_age", ob->query("mud_age"));
	me->set("shen", ob->query("shen"));
	me->set("luohan_winner", ob->query("luohan_winner"));
	me->set("dai", ob->query("dai"));
	me->set("is_beggar", ob->query("is_beggar"));
	me->set("readed", ob->query("readed"));
	me->set("betrayer", ob->query("betrayer"));

        ob->delete_temp("apply/short");
        ob->set_temp("apply/short", ({me->short()}));

        me->set("title", "第" + chinese_number(me->query("generation")) + "代巨鲸帮帮主");
        me->set("short", me->query("title") + " " + me->query("name") + "(jujing bangzhu)");
        me->delete("title");

        remove_call_out("do_clone");
        call_out("do_clone", 0, me, ob);

        return 1;
}

int do_clone(object me, object ob)
{
        object *inv, new;
        mapping hp_status, skill_status, map_status, prepare_status;
        string *sname, *mname, *pname;
        int i, temp;

        seteuid( geteuid(me) );

/* delete and copy skills */

        if ( mapp(skill_status = me->query_skills()) ) {
                skill_status = me->query_skills();
                sname  = keys(skill_status);

                temp = sizeof(skill_status);
                for(i=0; i<temp; i++) {
                        me->delete_skill(sname[i]);
                }
 }

        if ( mapp(skill_status = ob->query_skills()) ) {
                skill_status = ob->query_skills();
                sname  = keys(skill_status);

                for(i=0; i<sizeof(skill_status); i++) {
                        me->set_skill(sname[i], skill_status[sname[i]]);
                }
        }

/* delete and copy skill maps */

        if ( mapp(map_status = me->query_skill_map()) ) {
                mname  = keys(map_status);

                temp = sizeof(map_status);
                for(i=0; i<temp; i++) {
                        me->map_skill(mname[i]);
                }
        }

        if ( mapp(map_status = ob->query_skill_map()) ) {
     		mname  = keys(map_status);

                for(i=0; i<sizeof(map_status); i++) {
                        me->map_skill(mname[i], map_status[mname[i]]);
                }
        }

/* delete and copy skill prepares */

        if ( mapp(prepare_status = me->query_skill_prepare()) ) {
                pname  = keys(prepare_status);

                temp = sizeof(prepare_status);
                for(i=0; i<temp; i++) {
                        me->prepare_skill(pname[i]);
                }
        }

        if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
                pname  = keys(prepare_status);

                for(i=0; i<sizeof(prepare_status); i++) {
                        me->prepare_skill(pname[i], prepare_status[pname[i]]);
    		}
        }

/* unwield and remove weapon & armor */

        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) {
                destruct(inv[i]);
        }
        set("weapon", 0);
        set("armor", 0);

/* wield and wear weapon & armor */

        inv = all_inventory(ob);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]->query("weapon_prop/damage") > 100
                ||  inv[i]->query("armor_prop/armor") > 100 ) continue;

                if( inv[i]->query("weapon_prop") &&  inv[i]->query("equipped") )
 		{
                        carry_object(base_name(inv[i]))->wield();
                        me->set("weapon", base_name(inv[i]));
                }
 		else if( inv[i]->query("armor_prop") &&  inv[i]->query("equipped") ) {
                        carry_object(base_name(inv[i]))->wear();
                        me->set("armor", base_name(inv[i]));
                }
        }

/* copy entire dbase values */

        hp_status = ob->query_entire_dbase();

                me->set("str", hp_status["str"]);
                me->set("int", hp_status["int"]);
                me->set("con", hp_status["con"]);
                me->set("dex", hp_status["dex"]);
                me->set("age", hp_status["age"]);

                me->set("max_kee",    hp_status["max_kee"]);
                me->set("eff_qi",    hp_status["eff_qi"]);
                me->set("kee",        hp_status["kee"]);
                me->set("max_gin",  hp_status["max_gin"]);
                me->set("eff_jing",  hp_status["eff_jing"]);
                me->set("gin",      hp_status["gin"]);
                me->set("max_force", hp_status["max_force"]);
  		me->set("force",     hp_status["force"]);
                me->set("jiali",     hp_status["jiali"]);
                me->set("gender",    hp_status["gender"]);
                me->set("combat_exp",hp_status["combat_exp"]);

        save();

        tell_object(ob, "状态储存完毕。\n");

        new = new("/clone/npc/jujing");
        new->move("/d/quanzhou/jujing-bang");
        destruct(me);

        return 1;
}

int do_recover()
{
        object me, ob;
        mapping skill_status, map_status, prepare_status;
        string *sname, *mname, *pname;
        int i;

   	me = this_object();
        ob = this_player();

        if ( me->query("winner") != ob->query("id") )
                return notify_fail("你不是现任巨鲸帮主！\n");;

	if ( me->query("mud_age") > ob->query("mud_age"))
                return notify_fail("你想用 bug 谋利，呵呵！\n");

/* delete and copy skills */

        if ( mapp(skill_status = ob->query_skills()) ) {
                sname  = keys(skill_status);

                for(i=0; i<sizeof(skill_status); i++) {
                        ob->delete_skill(sname[i]);
                }
        }

        if ( mapp(skill_status = me->query_skills()) ) {
                sname  = keys(skill_status);

                for(i=0; i<sizeof(skill_status); i++) {
                        ob->set_skill(sname[i], skill_status[sname[i]]);
                }
        }
/* delete and copy skill maps */

        if ( mapp(map_status = ob->query_skill_map()) ) {
                mname  = keys(map_status);

                for(i=0; i<sizeof(map_status); i++) {
                        ob->map_skill(mname[i]);
                }
        }

        if ( mapp(map_status = me->query_skill_map()) ) {
                mname  = keys(map_status);

                for(i=0; i<sizeof(map_status); i++) {
                        ob->map_skill(mname[i], map_status[mname[i]]);
                }
        }

/* delete and copy skill prepares */

        if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
                pname  = keys(prepare_status);

                for(i=0; i<sizeof(prepare_status); i++) {
                        ob->prepare_skill(pname[i]);
                }
        }

        if ( mapp(prepare_status = me->query_skill_prepare()) ) {
                pname  = keys(prepare_status);

                for(i=0; i<sizeof(prepare_status); i++) {
                        ob->prepare_skill(pname[i], prepare_status[pname[i]]);
                }
        }

/* copy combat exp values */

	ob->set("combat_exp", me->query("combat_exp"));
	ob->set("is_beggar", me->query("is_beggar"));
	ob->set("mud_age", me->query("mud_age"));
	ob->set("shen", me->query("shen"));
	ob->set("luohan_winner", me->query("luohan_winner"));
	ob->set("dai", me->query("dai"));
	ob->set("readed", me->query("readed"));
	ob->set("betrayer", me->query("betrayer"));

        write("状态复元完毕。\n");

        return 1;
}
