// The latest changed by ysgl
// Data : 1997.11.1

inherit NPC;
#include <ansi.h>
int time_period(int timep, object me);
int ask_me();
void create()
{
        set_name("���޹�", ({ "liu luoguo", "liu", "luoguo" }) );
        set("title",GRN "��������" NOR);
        set("gender", "����");
        set("age", 40);
        set("long",
                "�����ű���˫����˸�Žƽݵ�Ŀ�⣬������˭���뵽�����ǵ������ࡣ\n");
        set("attitude", "peaceful");
        set("str", 50000);
        set("con", 30);
        set("int", 24);
        set("dex", 30000);
        set("chao_ting",9000000);
        set("force", 80000);
        set("max_force", 80000);
        set("force_factor", 1000);
        set("combat_exp", 20000000);
        set("score", 2000000);
        set_skill("dodge", 500);
        set_skill("force", 1000);
        set_skill("iron-cloth",1000);
	set("inquiry", ([
		"�ƾ�" : (: ask_me :),
	        ]) );

        setup();

 }
int accept_fight(object me)
{
        command("say �����ɹ󣡲�Ҫ��Ѱ��·��");
        return 0;
}
void init()
{
        add_action("give_quest", "quest");
} 
int ask_me()
{
	int j,combatexp;
	string title;
	object me;

 	string *guan = ({            
                      HIW"�׶�"NOR,
                      BLK"ͯ��"NOR,
                      RED"���"NOR,
                      GRN"����"NOR,
                      YEL"����"NOR,
                      BLU"����"NOR,
                      MAG"���׽�ʿ"NOR,
                      CYN"���׽�ʿ"NOR,
                      WHT"ͷ�׽�ʿ"NOR,
                      HIR"����"NOR,
                      HIG"Э���ѧʿ"NOR,
                      HIC"�Ļ����ѧʿ"NOR,
                      BLK"��Ӣ���ѧʿ"NOR,
                      HIB"���͵��ѧʿ"NOR,
                      RED"���θ��ѧʿ"NOR,
                      HIW"��Ԩ���ѧʿ"NOR,
                      GRN"��ͼ���ѧʿ"NOR,
                      GRN"������"NOR,
                        
        });

	string *chaoting = ({ 
                        "0",
                        "10000",
                        "30000",
                        "60000",
                        "100000",
                        "300000",
                        "800000",
                        "1500000",
                        "3000000",
                        "5000000",
                        "8000000",
                        "12000000",
                        "24000000",
                        "48000000",
                        "96000000",
                        "120000000",
                        "240000000",
                        "480000000",
                        });
	me=this_player();
	combatexp = (int) me->query("chao_ting");
        j = (int) me->query_skill("literate",1);
        if (combatexp<12000000) 
	combatexp = combatexp + j* j* j /40;
        for(j= sizeof(chaoting) - 1 ; j>=0; j--)
        {
                if( atoi(chaoting[j])  <= combatexp )
                        {    
                           
                           title=guan[j];
			   me->set("guantitle",title);
                            message_vision("���޹����˿�$N�Ŀ�����˵����
	$N���Եø�"+title+"�Ĺ�����\n", me);
                                break;
                        }
        }      
	return 1;          
}

int give_quest()
{
        mapping quest ;
        object me;
        int j, combatexp, timep,factor,num,tfinished;
        string tag = "1000000";
	string *levels = ({    
		        "0",
                        "1000",
                        "10000",
                        "100000",
			"500000",
                        "1000000",
           });
        me = this_player();      
// ���־������50����quest
/*	if( ((int) me->query("combat_exp") ) < 500000 ){
		message_vision("$N����$n���˰��Σ�˵��������λ"+RANK_D->query_respect(me)+
	"���黹��δ�����һ��ɣ���\n", this_object(), me);
		return 0;
	} */
// Let's see if this player still carries an un-expired task
       	if((quest =  me->query("quest")))
        {                                   
// ���漸���Ǹ�����ӳ�ʱ�䣬��Ҫһ����һ������̫���ˡ�	
     	if( ((int) me->query("task_time")) >  time() )
                return 0;
/*	else if( ( (int)me->query("delay") ) > 0 ){
		message_vision("$N΢΢�İ��˰��֣�����$nһ��˵����������ʱû�������㻹��������Ϊ�ϣ�ȥ�ɣ���\n", this_object(), me);
		return 0;
	}  */
	else {
                message_vision("���޹���$Nһ˦���䣬˵������û�ã����������㻹�������ҵķ��ϣ����ڸ���һ�λ��ᣮ\n", me);
                me->set("kee", me->query("kee")/2+1);
		me->set("quest_factor",10);
		tfinished = me->query("tfinished");
		if (tfinished <= -10)
			me->set("tfinished", tfinished - 1);
		else
			me->set("tfinished", 0);
        }
        }
        combatexp = (int) me->query("combat_exp");
        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
                if( atoi(levels[j])  <= combatexp )
                        {
	                         num=j;
                                 break;
                        }
        }
        if (!(tfinished =  me->query("tfinished"))) {
                me->set("tfinished",0);
                tfinished = 0;
                }
        if (tfinished >= 0) {
		num += (int) (tfinished / 3);
		if (num > (sizeof(levels)-1))
			num = sizeof(levels)-1;
		}
            else {
		num -= ((int)(-tfinished/3));
                if (num < 0) 
			 num = 0;
		}

        tag=levels[num];
	quest = ((string)"/quest/qlist"+num)->query_quest();
        timep = quest["time"];
        time_period(timep, me);
        if (quest["quest_type"] == "Ѱ")
        {
        tell_object(me,"�һء�"+quest["quest"]+"�����ҡ�\n" NOR);
        }
                if (quest["quest_type"] == "ɱ")
        {
        tell_object(me,"����ɱ�ˡ�"+quest["quest"]+"����\n" NOR);
        }
        quest["exp_bonus"]=quest["exp_bonus"];
        quest["pot_bonus"]=quest["pot_bonus"];
        quest["score"]=quest["score"];

        me->set("quest", quest);
        me->set("task_time", (int) time()+(int) quest["time"]);
/*	me->apply_condition("delay_time", (int)quest["time"]);
	me->set("delay", (int)quest["time"]); */
	return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        tell_object(me,HIW "���޹���˼��һ�����˵����\n����" + time + "��");
        return 1;
}
 int accept_object(object who, object ob)
{
        int bonus, exp, pot, score,factor;
        string test;
        mapping quest;

     /*   if( ob->query("money_id") && ob->value() >= 1000 )
        {
           if ( (int) who->query("quest") == 0)
           {
               command("smile");
               command("say ��λ" + RANK_D->query_respect(who) + " ,�ҾͲ�������");
                return 1;
            }
           who->set("quest", 0 );

           who->set("tfinished", 0);
           command("say �ðɣ������������˰ɡ�");
           return 1;
        }
        else if( ob->query("money_id") && ob->value() <= 10000 )
	{
 	       command("smile");
               command("say ��λ" + RANK_D->query_respect(who) + " ,�ҾͲ�������");
 		return 1;
	}	  */  
        if( ob->is_character())
        {
        tell_object(who,"���޹�˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        }
        if(userp(ob) || !(quest =  who->query("quest")))
        {
        tell_object(who,"���޹�˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        }
        if( ob->name(1) != quest["quest"])
        {
        tell_object(who,"���޹�˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        }
        if ((int) who->query("task_time") < time() )
        {
        tell_object(who,"���޹�˵�������ϧ����û����ָ����ʱ������ɣ�\n");
                        return 1;
        }
        else
        {
        tell_object(who,"���޹�˵������ϲ�㣡���������һ������\n");
        exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2);
        pot = exp/5+1;
        score = exp/2 + random(exp);
        factor=(int)who->query("quest_factor");
	factor=factor+10;
        if (factor>500) factor=500;
	who->set("quest_factor",factor);
        if (factor)
        {
                exp=exp*factor/10;
                pot=pot*factor/10;
                score=score*factor/10;
                score=score;
         }
        bonus = (int) who->query("combat_exp");
        bonus += exp;
        who->set("combat_exp", bonus);
        bonus = (int) who->query("potential");
        bonus = bonus - (int) who->query("learned_points");
        bonus = bonus + pot;
        bonus += (int) who->query("learned_points");
        who->set("potential", bonus );
        bonus = (int) who->query("chao_ting");
        bonus += score;
        who->set("chao_ting", bonus);
        tell_object(who,HIW"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n" +
        chinese_number(score)+"�㳯͢���ζ�\n"NOR);
        who->set("quest", 0 );
                        return 1;
        }
}
