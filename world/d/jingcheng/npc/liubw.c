// The latest changed by ysgl
// Data : 1997.11.1

inherit NPC;
#include <ansi.h>
int ask_me();

void create()
{
        set_name("������", ({ "liu bowen", "liu", "bowen" }) );
        set("title",GRN "��������" NOR);
        set("gender", "����");
        set("age", 40);
        set("long",
                "���ǵ������࣬��ּ�࿼��Ϊ����ѡ���˲š�\n");
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
                            message_vision("�����¿��˿�$N�Ŀ�����˵����
	$N���Եø�"+title+"�Ĺ�����\n", me);
                                break;
                        }
        }      
	return 1;          
}

