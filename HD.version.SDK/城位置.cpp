#include "GameDataStruct.h"

// ƒOƒŠƒbƒhÀ•W“¯u‚ÌŒ¸ZBÀ•W‚`¨À•W‚a‚ÌƒxƒNƒgƒ‹‚ğ‹‚ß‚é‚Ì‚ÉA’ÊíA‚a|‚`‚ğ‚·‚é‚¾‚ë‚¤‚©‚çB
éƒOƒŠƒbƒhƒxƒNƒgƒ‹Œ^^ operator-(éƒOƒŠƒbƒhˆÊ’uŒ^^ ˆÊ’u‚P, éƒOƒŠƒbƒhˆÊ’uŒ^^ ˆÊ’u‚Q) {
	éƒOƒŠƒbƒhƒxƒNƒgƒ‹Œ^^ ‚u = gcnew éƒOƒŠƒbƒhƒxƒNƒgƒ‹Œ^();
	‚u->‚w = ˆÊ’u‚P->‚w - ˆÊ’u‚Q->‚w;
	‚u->‚x = ˆÊ’u‚P->‚x - ˆÊ’u‚Q->‚x;
	return ‚u;
}

